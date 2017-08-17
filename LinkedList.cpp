template <class U>
struct Node
{
	Node<U>* pointer;
	U data; 	
};

template <class T>
class LinkedList {
	Node<T>* firstNode;
	Node<T>* lastNode;
	Node<T>* currentNode;
	
public:
	LinkedList() {
		firstNode = new Node<T>();
		lastNode = currentNode = firstNode;
	}
	LinkedList(const LinkedList &obj){
		firstNode = new Node<T>();
		firstNode->data = obj.firstNode->data;
		currentNode = firstNode;
		while(obj.next()){
			Node<T>* temp = currentNode;
			currentNode = new Node<T>();
			temp->pointer = currentNode;
			currentNode->data = obj.currentNode->data;
		}
	}	
	~LinkedList(){
		currentNode = firstNode;
		do{
			delete(currentNode);
		}
		while(this->next());
	}
	void insert(int index,T data){
		Node<T>* temp = currentNode;
		currentNode = firstNode;
		if(index <= 0) {
			Node<T>* newFirst = new Node<T>();
			newFirst->pointer = firstNode;
			newFirst->data = data;
			firstNode = newFirst;
		}else{
			for (int i = 0; i < index - 1; i++)
			{
				this->next();
			}
			Node<T>* newNode = new Node<T>();
			newNode->pointer = currentNode->pointer;
			currentNode->pointer = newNode;
			newNode->data = data;
		}
		currentNode = temp;
	}
	void push(T data){
		Node<T>* newNode = new Node<T>();
		newNode->pointer = nullptr;
		newNode->data = data;
		lastNode->pointer = newNode;
		lastNode = newNode;
	}
	bool next(){
		if(currentNode->pointer == nullptr) {
			return false;
		}else{
			currentNode = currentNode->pointer;
			return true;
		}
	}
	void sort()
	{
		int index = 0;
		Node<int> *temp = new Node<int>();
		Node<int> *tempTwo = new Node<int>();
		currentNode = firstNode;
		temp = firstNode;
		this->next();

			for(int i = 0; i < this->length(); ++i)
			{
				++index;
				while(temp->data > currentNode->data)
				{
					tempTwo->data = currentNode->data;
					currentNode->data = temp->data;
					temp->data = tempTwo->data;

					if(temp->data > currentNode->data)
					{
						setCurrentNode(index - 2);
						temp = currentNode;
						this->next();
					}
				}
				setCurrentNode(index);
			}
			
		
	}

	void setCurrentNode(int index)
	{
		currentNode = firstNode;
		if(index != 0)
		{
			while(index > 1 && this->next())
			{
				--index;
			}
		}
		
	}
	
	void set(T data){
		currentNode->data = data;
	}
	T get(){
		return currentNode->data;
	}
	int length(){
		Node<T>* temp = currentNode;
		currentNode = firstNode;
		int count = 1;
		if(firstNode != nullptr) {
			while(this->next()){
				count++;
			}
			currentNode = temp;
			return count;
		} else{
			currentNode = temp;
			return 0 ;
		}
	}
};