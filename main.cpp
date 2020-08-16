#include<iostream>
using namespace std;
int count;
#define INFINITY 9999


int waste_check(float ht_bin, float lvl)   //Level of Waste Check (Fn1)
{
    float chk = 0.6 * ht_bin;
    if(lvl > chk)
        return 1;
    else
        return 0;
}
int waste_check(float temp)     //Temperature Check of Waste (Fn2)
{
    if(temp>20)
        return 1;
    else
        return 0;
}
int waste_check(int ppm)        //Odour Check of Waste (Fn3)
{
    if(ppm>15)
        return 1;
    else
        return 0;
}
int waste_check(float ht_bin, int depth)    //Type Of Waste Check (Fn4)
{
    float chk = 0.4 * ht_bin;
    if(depth>ht_bin)
        return 1;
    else
        return 0;
}


int periodic_chk(int day)       //Weekly Waste pickup (Fn5)
{
    if(day>=7)
        return 1;
    else
        return 0;
}


int aerosol(float temp, int ppm)        //Aerosol Spray Check (Fn6)
{
    int t_chk,ppm_chk;
    t_chk = waste_check(temp);
    ppm_chk = waste_check(ppm);
    if (t_chk && ppm_chk)
        cout<<"Aerosol hit";
    else
        cout<<"Aerosol not hit";
}

int waste_pickup(int fn1,int fn2,int fn3,int fn4,int fn5)   //Condition to pickup waste
{
    if(fn1)
        return 1;
    else if(fn2 && fn3)
        return 1;
    else if(fn4 && fn3) 
        return 1;
    else if(fn5)
        return 1;
    else 
        return 0;
}



int main()
{
    float ht_bin,lvl,temp;
    int ppm,depth,day;
    int Fn1,Fn2,Fn3,Fn4,Fn5,bin[5];
    int i,j;
    
    for(i=0;i<5;i++)
    {
    cout<<"\n\tBin No.: "<<i<<"\n";
    cout<<"Enter Height of bin: ";
    cin>>ht_bin;
    cout<<"Enter Level of waste: ";
    cin>>lvl;
    cout<<"Enter Temperature of waste: ";
    cin>>temp;
    cout<<"Enter Level of Odour(in ppm): ";
    cin>>ppm;
    cout<<"Enter depth of liquid waste: ";
    cin>>depth;
    cout<<"Enter number of days since last waste pickup: ";
    cin>>day;
    Fn1 = waste_check(ht_bin,lvl);
    Fn2 = waste_check(temp);
    Fn3 = waste_check(ppm);
    Fn4 = waste_check(depth);
    Fn5 = periodic_chk(day);
    if(Fn2 && Fn3) 
        aerosol(temp,ppm);
    bin[i] = waste_pickup(Fn1,Fn2,Fn3,Fn4,Fn5);
    }
    
    int flag=1,count=0;
    cout<<"\nBins which are filled and need to be picked up are: \n";   
    /*if the different parameters to pick up the waste are satisified then they 
    return a boolean value which is stored in an array
    */
    for(i=0;i<5;i++)
    {
        if(bin[i]==1)
        {
        cout<<"Bin "<<i<<"\t";
        flag = 0;
        count++;
        }
    }
    
    
    if (flag == 1)          //if none of the bins are filled then exit the code
    {
        cout<<"No bin";
        exit(0);
    }
    else                    //else making the shortest path to collect the bins
    {
        int loc[5][5] = {{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}};
        int bin_loc[count][count];
        int x=0,y=0;
        for(i=0;i<5;i++)        //Choosing those bins only which are filled 
        {
            if(bin[i]==1)
            {
                for(j=0;j<5;j++)
                {
                    if(bin[j]==1)
                    {
                    bin_loc[x][y]=loc[i][j];
                    y++;
                    }
                }
                y=0;
                x++;
            }
        }
        // Using dijkstra algorithm to calculate the shortest path for bin collection
        int n=count;
        int startnode=0;
        int cost[count][count],distance[count],pred[count];
        int visited[count],ct,mindistance,nextnode,i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            if(bin_loc[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=bin_loc[i][j];
        for(i=0;i<n;i++) 
        {
            distance[i]=cost[startnode][i];
            pred[i]=startnode;
            visited[i]=0;
        }
        distance[startnode]=0;
        visited[startnode]=1;
        ct=1;
        while(ct<n-1) 
        {
            mindistance=INFINITY;
            for(i=0;i<n;i++)
                if(distance[i]<mindistance&&!visited[i]) {
                mindistance=distance[i];
                nextnode=i;
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
        if(mindistance+cost[nextnode][i]<distance[i]) {
            distance[i]=mindistance+cost[nextnode][i];
            pred[i]=nextnode;
        }
        ct++;
        }
        for(i=0;i<n;i++)
        if(i!=startnode) {
         cout<<"\nDistance of bin "<<i<<"="<<distance[i];
            cout<<"\nPath="<<i;
            j=i;
        do {
         j=pred[j];
         cout<<"<-"<<j;
        }while(j!=startnode);
        }
    }
    return 0;
}