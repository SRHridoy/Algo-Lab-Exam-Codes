#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int profit,weight;
    Item(){}
    Item(int profit, int weight){
        this->profit = profit;
        this->weight = weight;
    }
};

static bool cmp(struct Item a,struct Item b){
    double r1 = (double)a.profit/(double)a.weight;
    double r2 = (double)b.profit/(double)b.weight;
    return r1>r2;
}

double fractional_knap_sack(struct Item items[],int n, int maxWeight){
    sort(items,items+n,cmp);
    double maxProfit = 0.0;
    for(int i = 0; i < n; i++){
        if(items[i].weight<=maxWeight){
            maxWeight-=items[i].weight;
            maxProfit += items[i].profit;
        }else{
            maxProfit += items[i].profit*((double)maxWeight/(double)items[i].weight);
            break;
        }
    }

    return maxProfit;
}

int main(){

    int n;
    cin >> n;
    Item items[n];
    for(int i = 0; i < n; i++){
        int profit,weight;
        cin >> profit >> weight;
        items[i].profit = profit;
        items[i].weight = weight;
    }

    int maxWeight;
    cin >> maxWeight;

    double maxProfit = fractional_knap_sack(items,n,maxWeight);
    
    cout << maxProfit << endl;
}