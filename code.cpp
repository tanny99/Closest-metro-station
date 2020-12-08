	#include <bits/stdc++.h>
	#include <cmath> 
	#include <iostream>
	#include <string>
	#include <fstream>
    #define V 50 
	using namespace std;

	int i=0,n=50;
	double g1,g2;
	double a[50][50],pp[50];
	double lat1[200],long1[200],num_double;

int minDistance(double dist[],  
                bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
void printlist(int x);

void printPath(double parent[], int j) 
{ 
      
   
    if (parent[j] == - 1)
    	return; 

    printPath(parent, parent[j]); 
  
    cout<<" ";
	printlist(j);
	cout<<endl;
} 


void printSolution(double dist[], int n, double parent[],int src,int final) 
{ 
	cout<<"Vertex\t Distance "<<endl; 
    for (int i = 1; i < n; i++) 
    { 
		if(i==final)
		{
       		cout<<src<<" -> "<<i<<"\t "<<dist[i]<<endl; 
			cout<<"Path is : "<<endl;
    		printPath(parent, i); 
			cout<<endl;
		}
    } 
} 




void dijkstra(double graph[V][V], int src, int final) 
{ 
      
    
    double dist[V];  
	
    bool sptSet[V]; 
  
 
    double parent[V]; 
  
 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
  
 
    dist[src] = 0; 
  
 
    for (int count = 0; count < V - 1; count++) 
    { 
  
        int u = minDistance(dist, sptSet); 
  
  
        sptSet[u] = true; 
  
  
        for (int v = 0; v < V; v++){
  
  
            if (!sptSet[v] && graph[u][v]!=-1 && dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
   		}
	} 
  

	printSolution(dist, V, parent,src,final); 
} 
	void printlist(int x){
		if(x==999){
			string line;
			ifstream fin("metro_station.txt");
	   	 while(fin){
				getline(fin,line);
				cout<<line<<endl;
			}
			fin.close();
		}
		else{
				x++;
				string line;
				ifstream fin("metro_station.txt");
			 	while(fin){
					getline(fin,line);
					x--;
					if(x==0){
						break;
					}
				}
				
				cout<<line;
				fin.close();
		}
		
	}
		void printlist2(){
		
			string line;
			ifstream fin1("metro_reference.txt");
	   	 while(fin1){
				getline(fin1,line);
				cout<<line<<endl;
			}
			fin1.close();
		}
		
	
	double haversine(double lat1, double lon1, 
                        double lat2, double lon2) 
    { 

        double dLat = (lat2 - lat1) * 
                      M_PI / 180.0; 
        double dLon = (lon2 - lon1) *  
                      M_PI / 180.0; 
  

        lat1 = (lat1) * M_PI / 180.0; 
        lat2 = (lat2) * M_PI / 180.0; 
  

        double a = pow(sin(dLat / 2), 2) +  
                   pow(sin(dLon / 2), 2) *  
                   cos(lat1) * cos(lat2); 
        double rad = 6371; 
        double c = 2 * asin(sqrt(a)); 
        return rad * c; 
    } 
  
	void make_matrix(double latt, double longg){
		if(latt==999||longg==999){
			FILE * instFile1;
			FILE * instFile2;
			instFile1 = fopen("latitudes.txt", "r");
			instFile2= fopen("longitudes.txt", "r");
			while(i!=n){
				fscanf(instFile1, "%lf", &g1);
				fscanf(instFile2, "%lf", &g2);
				lat1[i]=g1; 
				long1[i]=g2; 
				i++;
		 	}
			fclose(instFile1);fclose(instFile2);


	    	for(i=0;i<n;i++)
	    		{
	    			for(int j=0;j<n;j++)
	    				{
	    					if(i==0&&j==1){
	    						a[i][j]=haversine(lat1[i],long1[i],lat1[j],long1[j]);
	    					}
	    					else if(i==n-1&&j==n-2){
	    						a[i][j]=haversine(lat1[i],long1[i],lat1[j],long1[j]);
	    					}
	    					else if(i>0&&abs(i-j)==1){
	    						a[i][j]=haversine(lat1[i],long1[i],lat1[j],long1[j]);
	    					}	
	    					else{
	    						a[i][j]=-1;
	    					}

	            			
	            		
	    				}
			   }   
		
		}
		else{
			FILE * instFile1;
			FILE * instFile2;
			instFile1 = fopen("latitudes.txt", "r");
			instFile2= fopen("longitudes.txt", "r");
			while(i!=n){
				fscanf(instFile1, "%lf", &g1);
				fscanf(instFile2, "%lf", &g2);
				lat1[i]=g1; 
				long1[i]=g2; 
				i++;
		 	}
			fclose(instFile1);fclose(instFile2);

			double min=99999;
			int min_node;
	    	for(i=0;i<n;i++){
	    		pp[i]=haversine(lat1[i],long1[i],latt,longg);
	    		if(pp[i]<min){
	    			min=pp[i];
	    			min_node=i;
	    		}
	    	}
	    	cout<<"Nearest metro station from your location is- ";
	    	printlist(min_node);
		cout<<endl;
		}
			
		}
	int main(){
		ios_base::sync_with_stdio(false);
   		 cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
		int i=0,n=157;
		double lat1[200],long1[200],num_double,g1,g2;
		string line;
		FILE * instFile1;
		FILE * instFile2;

		instFile1 = fopen("latitudes.txt", "r");
		instFile2= fopen("longitudes.txt", "r");
		cout<<endl<<endl<<"              "<<"WELCOME"<<endl;
	   cout<<"        "<<"Find Out Your Nearest Metro Station!!"<<endl;
	   int choice;
	   while(1)
	   {
	      cout<<"Press 1 to find the list of all metro stations"<<endl;
	      cout<<"Press 2 to find route to your desired metro station"<<endl;
	      cout<<"Press 3 to find the nearest metro station"<<endl;
	      cout<<"Press 4 to print refrence coordinates to there stations"<<endl;
	      cout<<"Press 5 to exit"<<endl;
	      cout<<"Enter choice:";
	      cin>>choice;
	      if(choice==1)
	      {
	      		printlist(999);
	      }
	      if(choice==2)
	      {
	      		cout<<"Write Your current metro station, by choosing the index from the list"<<endl;
	      		int root,final;
	      		cin>>root;
	      		cout<<"You choosed metro station- ";
	      		printlist(root);
	      		cout<<endl<<"Now choose your destination- "<<endl;
	      		cin>>final;
	      		cout<<"You choosed metro station- ";
	      		printlist(final);
				cout<<endl;
	      		cout<<"The shortest route is- "<<endl;
	      		make_matrix(999,999);
   				dijkstra(a,root,final) ; 
	      }
	      if(choice==3){
	      	double latt,longg;
	      	cout<<"Write Your current location, by choosing your current latitude(between -180to+180)"<<endl;
	      	cin>>latt;
	      	cout<<"Write Your current location, by choosing your current longitude(between -180to+180)"<<endl;
	      	cin>>longg;
	      	make_matrix(latt,longg);
	      }
	      if(choice==4){
	      	printlist2();
	      }
	      if(choice==5){
	       	break;
	       }
	    }


		return 0;
	}