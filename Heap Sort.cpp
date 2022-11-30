#include <iostream> 
using namespace std; 
class heap_tree
{
	int arr[];
	int left , right , largest , temp ;
	public:
		void heapify(int arr[], int , int );
		void heapSort(int arr[], int );
		void display(int arr[], int );
	
};

void heap_tree::heapify(int arr[], int n, int i)
{
	
	int largest = i; 
	int left = 2*i + 1; 
	int right = 2*i + 2;
	
	if (left < n && arr[left] > arr[largest]) 
		largest = left;
		
	if (right < n && arr[right] > arr[largest]) 
		largest = right;
		
	if (largest != i)                                         //largest is not root
	{ 
			temp = arr[i];
            arr[i]= arr[largest];
            arr[largest] = temp;
		//swap(arr[i], arr[largest]);
		
		heapify(arr, n, largest);               //call recursively for subtrees
	}
}

void heap_tree::heapSort (int arr[], int n)
{
	
	for (int i = n/2 -1; i >= 0; i--) 
		heapify(arr, n, i);                           //create heap
	for (int i = n - 1; i >= 0; i--)
	 { 
		temp = arr[0];
        arr[0]= arr[i];
        arr[i] = temp;
		//swap(arr[0], arr[i]); 

		heapify(arr, i, 0);                                    //max heap from reduced heap
	} 
}

void heap_tree::display(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	} 
	 

}

int main()
{
	heap_tree h;
	int n;

	
	cout << "Enter the number of elements: ";
   	cin >> n;
	int arr[n]; 
	cout << "Enter elements:" << endl;
	for(int i = 0; i<n; i++) 
	{
      	cin >> arr[i];
   	}
   	
	 
	cout << "\nArray before Sorting: "<<endl;
	h.display(arr, n);
   	
	h.heapSort(arr, n); 

	cout<<endl;
	
	cout << "\nSorted array is "<<endl; 
	h.display(arr, n);
	 
	return 0;
}
