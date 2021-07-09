import java.util.*;

public class HeapSort {

	public static void buildHeap(int arr[])
	{
		int n = arr.length;

		
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		
		for (int i = n - 1; i > 0; i--) {
			
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

		
			heapify(arr, i, 0);
		}
	}

	
	static void heapify(int arr[], int n, int i)
	{
		int largest = i; 
		int l = 2 * i + 1; 
		int r = 2 * i + 2; 

		
		if (l < n && arr[l] > arr[largest])
			largest = l;

		
		if (r < n && arr[r] > arr[largest])
			largest = r;

		
		if (largest != i) {
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;
			heapify(arr, n, largest);
		}
	}

	
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	
	public static void main(String args[])
	{
	    Scanner sc=new Scanner(System.in);
	    Random rd=new Random();
		System.out.println("Enter the size");
		int n = sc.nextInt();
		int array[]=new int[n];
		for(int i=0;i<n;i++)
		{
		   array[i]=rd.nextInt(30);
		}
	printArray(array);
	
		
		buildHeap(array);

		System.out.println("Sorted array is");
		printArray(array);
	}
}

