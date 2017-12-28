#include <iostream>
#include <iomanip>
using namespace std;

class seqQueue
{
 private:
     int *arr;
     int size;
     int front,rear;
public:
    seqQueue(int initSize=10){
        arr=new int[initSize];
        size=0;
        front=rear=0;
    }
    ~seqQueue(){
        delete []arr;
    }

    void enQueue(const int&x){
        arr[++rear]=x;
        ++size;
    }
    void deQueue(){
        ++front;
        --size;
    }
    int getHead(){
        return arr[front+1];
    }
    bool isEmpty(){
        return front==rear;
    }
    int getSize(){
        return size;
    }
};

int main()
{
    int n,p,q;
    double a,b;
    cin>>n;
    seqQueue car(n+20);
    seqQueue truck(n+20);

    for(int i=1;i<=n;++i){
        cin>>p>>q;
        if(p==0) {car.enQueue(q);}
        else {truck.enQueue(q);}
    }

    int size_car=car.getSize();
    int size_truck=truck.getSize();

    int cur_time=0;
    int ans_car=0,ans_truck=0;
    int i,j;
    while(!car.isEmpty()&&!truck.isEmpty()){
        for(i=0;i<8;++i){
            if(car.getHead()<=cur_time){
                ans_car+=cur_time-car.getHead();
                car.deQueue();
            }
            else break;
        }
        for(j=1;j<=10-i;++j){
            if(truck.getHead()<=cur_time){
                ans_truck+=cur_time-truck.getHead();
                truck.deQueue();
            }
            else break;
        }
        cur_time+=10;
    }

    while(!car.isEmpty()){
        for(i=1;i<=10;++i){
            if(car.getHead()<=cur_time){
                ans_car+=cur_time-car.getHead();
                car.deQueue();
            }
            else break;
        }
        cur_time+=10;
    }

    while(!truck.isEmpty()){
        for(i=1;i<=10;++i){
            if(truck.getHead()<=cur_time){
                ans_truck+=cur_time-truck.getHead();
                truck.deQueue();
            }
            else break;
        }
        cur_time+=10;
    }

    if(size_car!=0&&size_truck!=0){
        a=ans_car*1.0/size_car;
        b=ans_truck*1.0/size_truck;
    }
    else if(size_car==0){
        a=0;
        b=ans_truck*1.0/size_truck;
    }
    else{
        a=ans_car*1.0/size_car;
        b=0;
    }
    cout<<setprecision(3)<<fixed<<a<<' '<<b;

    return 0;
}
