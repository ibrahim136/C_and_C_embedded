#include <iostream>

char is_integer(float* temp);

void Define_Integer(int* n, char arr[]);

void Define_Array_Integer(int* n, int i);

void Define_array(int* arr, int n);

char main_menu();

class Array {
private:
	int* ptr;
	int size;
	int capacity;
public:
	Array() {
		size = 0;
		capacity = 2;
		ptr = new int[capacity];
	}
	Array(int temp[],int size) {
		this->size = size;
		capacity = size > 0 ? size * 2 : 2;
		ptr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = temp[i];
		}
	}
	Array(const Array& other) {
		size = other.size;
		capacity = other.capacity;
		ptr = new int[capacity];
		for (int i = 0; i < size; i++) {
			ptr[i] = other.ptr[i];
		}
	}
	~Array() {
		delete[] ptr;
	}
	void display() {
		for (int i = 0; i < size; i++) {
			std::cout << ptr[i] << " ";
		}
		std::cout << "\n\n";
	}
	bool check_space() {
		if (size >= capacity) {
			capacity *= 2;
			int* temp = new int[capacity];
			if (temp == nullptr) {
				return false;
			}
			for (int i = 0; i < size; i++) {
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
		}
		return true;
	}
	bool add(int value) {
		if (!check_space()) {
			std::cout << "failed to reallocate memory";
			return false;
		}
		ptr[size++] = value;
		return true;
	}
	bool insert(int value, int index) {
		if (!check_space()) {
			std::cout << "failed to reallocate memory";
			return false;
		}
		else if (index >=size) {
			std::cout << "there's no such element";
			return false;
		}
		for (int i = size; i > index; i--)
		{
			ptr[i] = ptr[i - 1];
		}
		ptr[index] = value;
		size++;
		return true;
	}
	bool delete_(int index) {
		if (index >= size) {
			std::cout << "there's no such element";
			return false;
		}
		for (int i = index; i <size-1; i++)
		{
			ptr[i] = ptr[i + 1];
		}
		ptr[size-1] = 0;
		size--;
		return true;
	}
	int search(int value)
	{
		int index = -1;
		if (index >= size) {
			std::cout << "there's no such element";
			return index;
		}
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] == value) {
				index = i;
				break;
			}
		}
		return index;
	}
	int get(int index) const {
		if (index >= size) {
			std::cout << "there's no such element";
			return -1;
		}
		return ptr[index];
	}
	bool set(int value,int index) {
		if (index >= size) {
			std::cout << "there's no such element";
			return false;
		}
		ptr[index] = value;
		return true;
	}
	int max() {
		int max = ptr[0];
		for (int i = 0; i < size; i++) {
			if (max < ptr[i]) {
				max = ptr[i];
			}
		}
		return max;
	}
	int min() {
		int min = ptr[0];
		for (int i = 0; i < size; i++) {
			if (min > ptr[i]) {
				min = ptr[i];
			}
		}
		return min;
	}
	void reverse() {
		int left = 0;
		int right = size - 1;
		while (left < right) {
			int temp = ptr[left];
			ptr[left] = ptr[right];
			ptr[right] = temp;
			left++;
			right--;
		}
	}
	void shift_left(int cnt) {
		if (cnt > size) {
			delete[] ptr;
			ptr = nullptr;
			size = 0;
			capacity = 2;
			return;
		}
		while (cnt--) {
			delete_(0);
		}
	}
	void shift_right(int cnt) {
		while (cnt--) {
			insert(0,0);
		}
	}
	void rotate_right(int cnt) {
		while (cnt--) {
			add(ptr[0]);
			shift_left(1);
		}
	}
	void rotate_left(int cnt) {
		while (cnt--) {
			insert(ptr[size - 1], 0);
			delete_(size - 1);
		}
	}
	Array merge(const Array &x,const Array &y) {
		int* temp_array = new int[x.size + y.size];
		int temp_index = 0;
		for (int i = 0; i < x.size; i++)
		{
			temp_array[temp_index++] = x.get(i);
		}
		for (int i = 0; i < y.size; i++)
		{
			temp_array[temp_index++] = y.get(i);
		}
		Array ret(temp_array, x.size + y.size);
		delete[] temp_array;
		return ret;
	}
	int sum() {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += ptr[i];
		}
		return sum;
	}
	float average() {
		return (float)sum() / size;
	}
	void replace(int f, int s) {
		int temp = ptr[f];
		ptr[f] = ptr[s];
		ptr[s] = temp;
	}
};

Array Define_Array_Class();



int main() {
	int temp[] = {1,2,3,4};
	Array x(temp, 4);
	std::cout << "Array x:\n";
	x.display();
	x.add(20);
	std::cout << "Array x after adding 20:\n";
	x.display();
	x.insert(7, 2);
	std::cout << "Array x after inserting 7 at index 2:\n";
	x.display();
	x.delete_(2);
	std::cout << "Array x after deleting element with index 2:\n";
	x.display();
	int search_x = x.search(4);
	std::cout << "index of element that has value of \"4\": " << search_x << "\n\n";
	std::cout << "value of element with index 4: "<< x.get(4) << "\n\n";
	x.set(500,2);
	std::cout << "Array x after setting element with index 2 with value of 500:\n";
	x.display();
	std::cout << "Maximum Value int the Array: " << x.max() << "\n\n";
	std::cout << "Minimum Value int the Array: " << x.min() << "\n\n";
	x.reverse();
	std::cout << "Array x Reversing:\n";
	x.display();
	x.shift_left(2);
	std::cout << "Array x after 2 left shifting:\n";
	x.display();
	x.insert(66, 0);
	std::cout << "Array x after inserting 66 at index 0:\n";
	x.display();
	x.shift_right(2);
	std::cout << "Array x after 2 right shifting:\n";
	x.display();
	x.rotate_right(1);
	std::cout << "Array x after 1 right rotating:\n";
	x.display();
	x.rotate_left(2);
	std::cout << "Array x after 2 left rotating:\n";
	x.display();
	std::cout << "\n\n\n";
	std::cout << "Array x:\n";
	x.display();
	Array y(temp, 4);
	std::cout << "Array y:\n";
	y.display();
	Array z  (x.merge(x, y));
	std::cout << "Array z which is a merging between x and y:\n";
	z.display();
	std::cout << "Sum of Array z: " << z.sum() << "\n\n";
	std::cout << "Average of Array z: " << z.average() << "\n\n";

	std::cout << "Array z before replacing the values of index 2 and 5:\n";
	z.display();
	z.replace(2, 5);
	std::cout << "Array z after replacing the values of index 2 and 5:\n";
	z.display();
}



void Array_Management_System() {
	int choice;
	int arrays_count = 0;
	Array* arrays = nullptr;
	do {
		choice = main_menu();
		switch (choice)
		{
		case 1:
			break;
		case 5: {
			int i;
			delete[] arrays;
			break;
		}
		}
	} while (choice != 5);
}

char main_menu() {
	int choice;
	do
	{
		std::cout<<"======= Array Management System =======\n\n";
		std::cout << "1 . Add New Array\n";
		std::cout << "2 . Delete Array\n";
		std::cout << "3 . Display Array\n";
		std::cout << "4 . Add/Append a new element to array\n";
		std::cout << "5 . Insert a new element to array\n";
		std::cout << "6 . Get specific exisiting element\n";
		std::cout << "7 . Set another value to an exisiting element\n";
		std::cout << "8 . Get maximum value";
		std::cout << "9 . Get minimum value\n";
		std::cout << "10. Reverse the Array\n";
		std::cout << "11. Shift right/left\n";
		std::cout << "12. Rotate right/left\n";
		std::cout << "13. Merge two Arrays\n";
		std::cout << "14. Get the Sum\n";
		std::cout << "15. Replace/Swap 2 elements\n";
		char message[] = "Enter your choice: ";
		Define_Integer(&choice, message);
		if (choice > 15 || choice < 1) {
			printf("Please enter a choice in the valid range (1~15)\n\n");
		}
	} while (choice > 15 || choice < 1);
	return choice;
}


Array Define_Array_Class(){
	int n;
	char message[] = "the size of array";
	Define_Integer(&n, message);
	int* arr = new int[n];
	if (!arr) {
		printf("\nArray hasn't allocated... please try again later\n");
		return Array();
	}
	Define_array(arr, n);
	Array ret(arr, n);
	delete[] arr;
	return ret;
}

char is_integer(float* temp)
{
	return *temp == (int)*temp;
}

void Define_Integer(int* n, char arr[])
{
	float temp;
	bool check = true;
	while (check) {
		printf("Please enter %s: ", arr);
		check = (bool)(std::cin >> temp);;
		if (!check) {
			std::cout<< "You have entered non-integer input... please try again a positive integer input\n\n";
			check = true;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (!is_integer(&temp))
		{
			std::cout << "You have entered a decimal input... please try again a positive integer input\n\n";
			check = true;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (temp < 1) {
			std::cout << "You have entered non-positive input... please try again a positive integer input\n\n";
			check = true;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
		{
			*n = (int)temp;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			check = false;
		}
	}
}

void Define_Array_Integer(int* n, int i) {
	float temp;
	bool check = true;
	while (check) {
		std::cout << "Please enter element no. " << i+1 << " (index[" <<i << "]) : ";
		check = (bool)(std::cin >> temp);
		if (!check) {
			std::cout << "You have entered non-numerical input... please try again\n\n";
			check = true;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (!is_integer(&temp))
		{
			std::cout << "You have entered a decimal input... please try again a positive integer input\n\n";
			check = true;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
		{
			*n = (int)temp;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			check = false;
		}
	}
}

void Define_array(int* arr, int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		Define_Array_Integer(&arr[i], i);
	}
}

