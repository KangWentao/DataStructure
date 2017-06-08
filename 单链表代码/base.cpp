//基本的输入输出及比较操作
//输入数据
template <class T>
void Input(T &x){
	cin>>x;
}

void Input(STU &x){
	cin>>x.num;	
	cin>>x.name;
}

//简单类型数据输出
template <class T>
void Print(T x){
	cout<<x<<"  ";
}

//结构体类型数据输出
void Print(STU x){
    cout<<x.num<<"  ";
	cout<<x.name<<endl;
}

template <class T>
bool Compare(T x, T y){
	if (x<y) return true;
	else return false;
}

bool Compare(STU x,STU y){
	if (x.num<y.num) return true;
	else return false;
}