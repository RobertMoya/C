/***********************
 * Robert Moya
 * time complexity: O(n)
 * the problem consisted of building an array and passing it through as a poiinter to functions such as average and variance and inputing user input as the values for the array. 
 * sketch of solution: I built an array and set its max to 100 and then ran values from the keyboard to construct my array and how many values were inputed to get the size and then pass it through the functions and return the values and cout the values.
 * 100%
 * ******************/

#include <iostream>
#include <string>
#include <cstdlib>	
#include <cmath>

using namespace std;

float avg(float array[], float size)
{
	float return_value;
	float avg;
	for(int i=0; i<size; i++){
		return_value = array[i]+ return_value;
	}	
	avg= (return_value / size);
	return  avg;
	
	
}
float var( float array[], float b, float size)
{
	float temp = 0.0;
	float var = 0.0;
	float sum=0.0;
	for (int i=0; i<size; i++){
		temp  = (((array[i] - b) * (array[i]-b)));
		sum = temp+ sum;
	}
	
	var = sqrt (sum / (size-1)); 
	return (var);
	
}

int main()
{
	float user_numbers;
	float ex[100];
	int i=0; 
	float n=0;
	float average, standard_deviation;

	cout<< " please enter numbers less than 99 in total \n ";
	cin >> user_numbers;
	
	while (!cin.eof() && i !=100 ){
		ex[i]= user_numbers;
		i++ , n++;
		cin >> user_numbers;
	}
			
		if ( i == 100)
			cout << " ERROR ";
		else if ( i ==0 ){
			cout << " Error needs to be bigger than 0";
			return 0;
		}
		else if (i ==1){ 
			cout << " Error needs to be bigger than 1"; 
			return 0;
		}
		else
			average = avg(ex,n);
			standard_deviation = var(ex, average, n);
				cout << "the average of the numbers are "<< average<< endl;
				cout << "the standard deviation of the numbers are " << standard_deviation << endl;
}	

			
			
			
		
	
			
