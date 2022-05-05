import java.util.*;
public class SORT {
    public static void insertion(int[] arr){
        for(int i=1;i<arr.length;i++){
            int key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }
    public static void mergeSort(int[] arr,int startIndex, int endIndex) {
        if (startIndex < endIndex && (endIndex - startIndex) >= 1) {
            int k=(endIndex+startIndex)/2;
            mergeSort(arr,startIndex,k);
            mergeSort(arr,k+1,endIndex);
            merge(arr,startIndex, endIndex);
        }
    }

    public static void merge(int[] inputArray,int startIndex, int endIndex) {
        ArrayList<Integer> mergedSortedArray = new ArrayList<Integer>();
        int mid=(startIndex+endIndex)/2;
        int x=startIndex;
        int k=mid+1;
        while(x<=mid && k<=endIndex){
            if(inputArray[x]<inputArray[k]){
                mergedSortedArray.add(inputArray[x]);
                x++;
            }else{
                mergedSortedArray.add(inputArray[k]);
                k++;
            }
        }
        while(x<=mid){
            mergedSortedArray.add(inputArray[x]);
            x++;
        }
        while(k<=endIndex){
            mergedSortedArray.add(inputArray[k]);
            k++;
        }
        int i = 0;
        int j = startIndex;
        while (i < mergedSortedArray.size()) {
            inputArray[j]=mergedSortedArray.get(i++);
            j++;
        }
    }
    public static int[] countingsort(int[] arr,int k){
        int[] count=new int[k+1];
        Arrays.fill(count,0);
        int size=arr.length;
        int[] out=new int[size];
        for(int i=0;i<size;i++){
            count[arr[i]]+=1;
        }
        for(int j=1;j<count.length;j++){
            count[j]=count[j-1]+count[j];
        }
        for(int i=0;i<size;i++){
            out[count[arr[i]]-1]=arr[i];
        }
        return out;
    }
    public static int[] pigeonholesort(int[] arr){
        int n=arr.length;
        int max = Arrays.stream(arr).max().getAsInt();
        int min = Arrays.stream(arr).min().getAsInt();
        int range=max-min+1;
        int[] out=new int[n];
        ArrayList<Integer>[] curr = new ArrayList[range];
        for(int i=0;i<n;i++){
            if(curr[arr[i]-min]==null){
                curr[arr[i]-min]=new ArrayList<>();
            }
            curr[arr[i]-min].add(arr[i]);
        }
        int x=0;
        for(int j=0;j<range;j++){
            if (curr[j]!=null) {
                for(int i=0;i<curr[j].size();i++){
                    out[x++]=curr[j].get(i);
                }
            }
        }
        return out;
    }
}
