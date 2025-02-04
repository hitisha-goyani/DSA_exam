#include<iostream>
#include<vector>


using namespace std;


// ------------------------------------------------------------linked list------------------------------------------------------//

class Node{

    public :
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class LL{
    public:

    Node *head;

    LL(){
        this->head=NULL;
    }

    void start(int ele){

        Node *obj = new Node(ele);
        obj->next = this->head;
        this->head = obj;




    }

    void view(){
        Node *ptr = this->head;
        while(ptr!=NULL){
            cout<<ptr->data<<" "<<ptr<<endl;
            ptr=ptr->next;
        }
    }

    

};
void link(){

        LL list;
        

    int nodes,ele;

    cout<<"nodes:";
    cin>>nodes;

    for(int i=1;i<=nodes;i++){

        cout<<"ele["<<i<<"]: ";
        cin>>ele;
        list.start(ele);
    }

list.view();

    }



//--------------------------------------------------------------merge sort------------------------------------------------------------//

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int> arr2;
    int left =low;
    int right = mid+1;


while(left<=mid && right<=high){

    if(arr[left]<=arr[right]){
        arr2.push_back(arr[left]);
        left++;
    }
    else
    {
        arr2.push_back(arr[right]);
        right++;
    }
}

while(left<=mid){
    arr2.push_back(arr[left]);
     left++;
}

while(right<=high){
    arr2.push_back(arr[right]);
    right++;
}

for(int i=low; i<=high; i++){

    arr[i]  = arr2[i-low];
}
}


int merge_sort(vector<int>&arr, int low,int high){

    if(low >= high){
        return 0;
    }
    int mid = (low+high)/2;

    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

void merge(vector<int> &arr){
   int n = arr.size();

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";  
    }

}


//------------------------------------------------------------------quick sort-----------------------------------------------------------------------------//

int first(vector<int> &arr,int low,int high){

    int last =arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){

        if(arr[j]<last){
            i++;
            swap(arr[i],arr[j]);
        }

    }
     swap(arr[i+1], arr[high]);
       return i+1;
}


int quick_sort(vector<int> &arr,int low,int high){

    if(low < high){

        int p = first(arr,low,high);

        quick_sort(arr,low,p-1);
         quick_sort(arr,p+1,high);

    }
}


void quick(vector<int> &arr){

    

    int n = arr.size();

    quick_sort(arr,0,n-1);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
                                             
    }

}


///--------------------------------------------------------------binary search--------------------------------------------------------------------//


void print_array(vector<int> &arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int binary_search(vector<int> &arr,int low,int high,int target){

    if(low>high){
        
        return -1;
    }

    int mid=(low+high)/2;

    if(arr[mid]==target){

        return mid; 
    }
    else if(arr[mid]>target){

        return binary_search(arr,low,mid,target);
    }

    else{
        return binary_search(arr,mid+1,high,target);
    }

    return -1;
}

void binary(vector<int> &arr){
    int n = 7;
    int t; 
    cout << "target:  ";
    cin >> t;


   int l_index =  binary_search(arr, 0, n, t);


   if(l_index == -1)
   {
    cout << "ele not found...!" << endl;
   }
   else{
    cout << "ele found at " << l_index << endl;
   }


}
//




int main(){
vector<int> arr = {3,4,8,9,6,7,5};
// int array[7] = {11, 25, 29, 32, 39, 44, 47};


int choice;



do{
    cout<<endl;
    cout<<"press 1 for create linklist ....!"<<endl;
    cout<<"press 2 for merge sort.....!"<<endl;
    cout<<"press 3 for quick sort....!"<<endl;
    cout<<"press 4 for binary search ...!"<<endl;
   

    cout<<"choice:";
    cin>>choice;
  

   

    switch(choice){

        case 1:
            link();
            

        break;

        case 2:
            merge(arr);
            
       
        break;

        case 3:
            quick(arr);
             

        break;

        case 4:
            binary(arr);
           
        
        break;

          default:
                cout << "enter valid choice " << endl;
                break;

    }

}while(choice!=0);


    return 0;
}