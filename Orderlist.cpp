/***************************************
 * Robert Moya
 * Homework3
 * 11/15/17
 * File Order.cpp
 * Time complexity: O(n) for ordered functions and also O(nlog(n)) for the unordered functions. 
 * Problem: The problem in this homework was to make for different functions
 * ordered_union, ordered_intersect, unordered_union, unordered_intersect
 * and to build our own main function to test the program.
 * Sketch of solution: The way I solved this program by the writting the Ordered 
 * first, and then when writing a unordered function by sorting the list brought in and 
 *	then call the ordered functions to do the proper outputs. 
 * 100% 
 * ********************/

#include <iostream>
#include <list>


using namespace std;
template< class T>
list <T> ordered_intersect(const list<T> & a, const list <T> & b)
{
	list<T> t;
	typename list<T>:: const_iterator i=a.begin();
	typename list<T>:: const_iterator j=b.begin();
	while (i != a.end() && j!= b.end())
		if(*i<*j)
			i++;
		else if (*j<*i)
			j++;
		else{
			t.push_back(*i);
			i++;
			j++;
		}
	return t;
}

template<class T>
list<T> ordered_union(const list <T> & a, const list<T> & b)
{
	list<T> t;
	typename list<T> :: const_iterator i=a.begin();
	typename list<T> :: const_iterator j=b.begin();
	
	while ( i != a.end() && j != b.end()){

		if ( *i< *j){
			t.push_back(*i);
			i++;
		}
		else if (*i > *j ){
			t.push_back(*j);
			j++;
		}
		else {
			t.push_back(*i);
			i++;
			j++;
		}
	}		
	while (i != a.end()){
		t.push_back(*i);
		i++;
	}	
	while (j != b.end()) {
		t.push_back(*j);
		j++;		
	}
	
	return t;	

} 
template<class T>
list<T> unordered_union(list<T> & a, list<T> & b)
{
	list<T> t;

	a.sort();
	b.sort();

	t= ordered_union(a,b);

	return t;
	
}					

template<class T>
list<T> unordered_intersect(list<T> &a, list<T> & b)
{

	list<T> t;
   	 
    a.sort();
    b.sort();

	t= ordered_intersect(a,b);
	
	return t;
}

void print(list<int> & p)
{
	list<int>::iterator i;
	for (i =p.begin(); i!= p.end(); ++i)
		cout<< *i << " ";
		cout <<"\n" << endl;
}

main()
{
	
	list <int> a1({1,2,3,4,5});
	list <int> a2({5,6,7,8,9});
	list <int> uo1({10,15,11,13,12});
	list <int> uo2({15,19,16,18,17});
	
	cout << "Ordered list 1" << endl;
	print (a1);
	cout << "Ordered list 2" << endl;
 	print(a2);
	list<int> temp;
	
	temp = ordered_intersect(a1,a2);
	cout<< "Ordered intersect" << endl;
	print(temp); 	

	temp = ordered_union(a1,a2);
	cout<< "Ordered union " << endl;
	print(temp);		
   	
	cout << "Unorder list 1 " << endl;
    print (uo1);
    cout << "Unorder list 2 " << endl;
    print(uo2);
	
	temp = unordered_union(uo1,uo2);
	cout<< "UnOdered union " << endl;
	print(temp);

	temp = unordered_intersect(uo1,uo2);
    cout<< "UnOdered intersect " << endl;
    print(temp);

	cout << " Program is successful " << endl;
	 
}	
