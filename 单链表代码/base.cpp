//����������������Ƚϲ���
//��������
template <class T>
void Input(T &x){
	cin>>x;
}

void Input(STU &x){
	cin>>x.num;	
	cin>>x.name;
}

//�������������
template <class T>
void Print(T x){
	cout<<x<<"  ";
}

//�ṹ�������������
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