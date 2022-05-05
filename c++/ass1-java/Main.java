import java.util.*;
import org.knowm.xchart.*;
import org.knowm.xchart.style.Styler;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
class Main{
    public static int[] reverse(int[] arr){
        int[] arr2=new int[arr.length];
        int x=0;
        for(int i=arr.length-1;i>=0;i--){
            arr2[x++]=arr[i];
        }
        return arr2;
    }
    public static double function(int[] array,int x){
        double time=0;
        int max = Arrays.stream(array).max().getAsInt();
        for(int i=0;i<10;i++){
            int[] copy=array.clone();
            long start=System.currentTimeMillis();
            if(x==1){
                SORT.insertion(copy);
                long end=System.currentTimeMillis();
                time+=end-start;
            }else if(x==2){
                SORT.mergeSort(copy,0,copy.length-1);
                long end=System.currentTimeMillis();
                time+=end-start;
            }else if(x==3){
                SORT.pigeonholesort(copy);
                long end=System.currentTimeMillis();
                time+=end-start;
            }else{
                SORT.countingsort(copy,max);
                long end=System.currentTimeMillis();
                time+=end-start;
            }
        }
        time/=10;
        return time;
    }
    public static void main(String args[]) throws IOException {
        String file1=args[0];
        BufferedReader reader = null;
        try {
            reader=new BufferedReader(new FileReader(file1));
            String line;
            int lineNumber = 0;
            int[] flowdur512 = new int[512];
            int[] flowdur1024 = new int[1024];
            int[] flowdur2048 = new int[2048];
            int[] flowdur4096 = new int[4096];
            int[] flowdur8192 = new int[8192];
            int[] flowdur16384 = new int[16384];
            int[] flowdur32768 = new int[32768];
            int[] flowdur65536 = new int[65536];
            int[] flowdur131072 = new int[131072];
            int[] flowdur251281 = new int[251281];
            //take input from csv file
            while ((line = reader.readLine()) != null) {
                String[] columns = line.split(",");
                if (lineNumber != 0) {
                    if (lineNumber <= 512) {
                        flowdur512[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 1024) {
                        flowdur1024[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 2048) {
                        flowdur2048[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 4096) {
                        flowdur4096[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 8192) {
                        flowdur8192[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 16384) {
                        flowdur16384[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 32768) {
                        flowdur32768[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 65536) {
                        flowdur65536[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 131072) {
                        flowdur131072[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                    if (lineNumber <= 251281) {
                        flowdur251281[lineNumber - 1] = Integer.parseInt(columns[7]);
                    }
                }
                lineNumber++;
            }
            reader.close();
            int[][] liste=new int[][]{flowdur512,flowdur1024,flowdur2048,flowdur4096,flowdur8192,flowdur16384,flowdur32768,flowdur65536,flowdur131072,flowdur251281};
            double[][] yAxis = new double[4][10];
            int current = 1;
            yAxis[0] = new double[10];
            for(int i=0;i<10;i++){
                yAxis[0][i]=function(liste[i],current);
            }
            current+=1;
            yAxis[1] = new double[10];
            for(int i=0;i<10;i++){
                yAxis[1][i]=function(liste[i],current);
            }
            current+=1;
            yAxis[2] = new double[10];
            for(int i=0;i<10;i++){
                yAxis[2][i]=function(liste[i],current);
            }
            current+=1;
            yAxis[3] = new double[10];
            for(int i=0;i<10;i++){
                yAxis[3][i]=function(liste[i],current);
            }
            // X axis data
            int[] inputAxis = {512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 251282};
            //to make sorted datas
            int[][] sorteddatas=new int[10][];
            for(int i=0;i<10;i++){
                SORT.mergeSort(liste[i],0,liste[i].length-1);
                sorteddatas[i]=liste[i];
            }
            double[][] y1Axis = new double[4][10];
            current = 1;
            y1Axis[0] = new double[10];
            for(int i=0;i<10;i++){
                y1Axis[0][i]=function(sorteddatas[i],current);
            }
            current+=1;
            y1Axis[1] = new double[10];
            for(int i=0;i<10;i++){
                y1Axis[1][i]=function(sorteddatas[i],current);
            }
            current+=1;
            y1Axis[2] = new double[10];
            for(int i=0;i<10;i++){
                y1Axis[2][i]=function(sorteddatas[i],current);
            }
            current+=1;
            y1Axis[3] = new double[10];
            for(int i=0;i<10;i++){
                y1Axis[3][i]=function(sorteddatas[i],current);
            }
            //to make reversed sorted data
            int[][] reverseddatas=new int[10][];
            for(int i=0;i<10;i++){
                reverseddatas[i]=reverse(sorteddatas[i]);
            }
            double[][] y2Axis = new double[4][10];
            current = 1;
            y2Axis[0] = new double[10];
            for(int i=0;i<10;i++){
                y2Axis[0][i]=function(reverseddatas[i],current);
            }
            current+=1;
            y2Axis[1] = new double[10];
            for(int i=0;i<10;i++){
                y2Axis[1][i]=function(reverseddatas[i],current);
            }
            current+=1;
            y2Axis[2] = new double[10];
            for(int i=0;i<10;i++){
                y2Axis[2][i]=function(reverseddatas[i],current);
            }
            current+=1;
            y2Axis[3] = new double[10];
            for(int i=0;i<10;i++){
                y2Axis[3][i]=function(reverseddatas[i],current);
            }
            /*System.out.println("RANDOM DATA");
            for(int i=0;i<10;i++){
                System.out.println((i+1)+". average of insertion "+yAxis[0][i]);
                System.out.println((i+1)+". average of merge "+yAxis[1][i]);
                System.out.println((i+1)+". average of pigeonhole "+yAxis[2][i]);
                System.out.println((i+1)+". average of counting "+yAxis[3][i]);
            }
            System.out.println("SORTED DATA");
            for(int i=0;i<10;i++){
                System.out.println((i+1)+". average of insertion "+y1Axis[0][i]);
                System.out.println((i+1)+". average of merge "+y1Axis[1][i]);
                System.out.println((i+1)+". average of pigeonhole "+y1Axis[2][i]);
                System.out.println((i+1)+". average of counting "+y1Axis[3][i]);
            }
            System.out.println("REVERSED SORTED DATA");
            for(int i=0;i<10;i++){
                System.out.println((i+1)+". average of insertion "+y2Axis[0][i]);
                System.out.println((i+1)+". average of merge "+y2Axis[1][i]);
                System.out.println((i+1)+". average of pigeonhole "+y2Axis[2][i]);
                System.out.println((i+1)+". average of counting "+y2Axis[3][i]);
            }*/
            // Save the char as .png and show it
            showAndSaveChart("Random Data", inputAxis, yAxis);
            showAndSaveChart("Sorted Data", inputAxis, y1Axis);
            showAndSaveChart("Reversed Sorted Data", inputAxis, y2Axis);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    public static void showAndSaveChart(String title, int[] xAxis, double[][] yAxis) throws IOException {
        // Create Chart
        XYChart chart = new XYChartBuilder().width(800).height(600).title(title)
                .yAxisTitle("Time in Milliseconds").xAxisTitle("Input Size").build();

        // Convert x axis to double[]
        double[] doubleX = Arrays.stream(xAxis).asDoubleStream().toArray();

        // Customize Chart
        chart.getStyler().setLegendPosition(Styler.LegendPosition.InsideNE);
        chart.getStyler().setDefaultSeriesRenderStyle(XYSeries.XYSeriesRenderStyle.Line);

        // Add a plot for a sorting algorithm
        chart.addSeries("Insertion", doubleX, yAxis[0]);
        chart.addSeries("Merge Sort", doubleX, yAxis[1]);
        chart.addSeries("Counting Sort", doubleX, yAxis[2]);
        chart.addSeries("Pigeonhole Sort", doubleX, yAxis[3]);

        // Save the chart as PNG
        BitmapEncoder.saveBitmap(chart, title + ".png", BitmapEncoder.BitmapFormat.PNG);

        // Show the chart
        new SwingWrapper(chart).displayChart();
    }
}
