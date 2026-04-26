#include<bits/stdc++.h>
using namespace std;

class heap {
    public:
    int arr[100];
    int size = 0;
    
    //constructor
    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        // insert karne ke liye sabse phale size ko increase karo 
        //phir uska index nikalo 
        //fir us index par insert kar do
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent = index /2;

            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return ;
            }
        }
    }
    void print() {
        for(int i = 1; i<= size; i++) {
            cout<<arr[i] << " ";
        } cout<<endl;
    }
    void deletefromHeap() {
        if(size == 0) {
            cout << " Nothing to delete" << endl;
            return;
        }
        //step ->1 put last elemnts into first index 
        arr[1] = arr[size];

        // step 2 : Remove last elements
        size--;

        // step 3 :  take root node to its correct position
        int i =1;
        while(i <= size) {
            int leftindex = 2 * i;
            int rightindex= 2 * i + 1;

            if(leftindex <= size && arr[i] < arr[leftindex]) {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex <= size && arr[i] < arr[rightindex]) {
                swap(arr[i],arr[rightindex]);
                i = rightindex;
            } else{
                return ;
            }
        }
    }
};

void heapify(int arr[], int n ,int i) {
    
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    //1 based index mai left <=n tak chlata hai 
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    } 
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n) {
    int size = n;
    int t = n;
    while( t > 1) {
        //step -> 1 
        swap(arr[t],arr[1]);
        //step -> 2
        t--;

        //step -> 3
        heapify(arr,t,1);
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52,50};
    int n = 5;
    
    for(int i = n/2 ; i > 0; i--) {
        heapify(arr,n,i);
    }
    cout<< "printing the array is" << endl;

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    //heapsort
    heapsort(arr,n);

    cout<< "printing the heapsort is" << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    // now we can use also build up function

    priority_queue<int>pq;
    pq.push(50);
    pq.push(55);
    pq.push(53);
    pq.push(52);
    pq.push(54);
    cout<<"Top of the elements is" <<pq.top()<<endl;

    priority_queue<int, vector<int>, greater<int>> pq1;
     pq1.push(50);
    pq1.push(55);
    pq1.push(53);
    pq1.push(52);
    pq1.push(54);

    cout<< " min heap is " << pq1.top();


    return 0;

}