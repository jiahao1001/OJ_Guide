#include<queue>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<utility>
#include<stdlib.h>
using namespace std;
typedef pair<int,int> PII;
struct Agent{
    int id; //0-25
    int floor;
    int next_room;
    int t;
    int pt;
    int ele;//0 in front of elevator, 1 in front of next room, 2 in room
};
bool operator<(const Agent &a1,const Agent& a2){
    if(a1.t==a2.t) return a1.id>a2.id;
    return a1.t>a2.t;
}
int start[26];//start time
vector<PII> rooms[26]; // room no, stay time
vector<string> logs[26];
int room_t[1020];
int elevator[20];
char buf[100];
void LOG(int id,int t1,int t2,string msg){
    sprintf(buf,"%02d:%02d:%02d %02d:%02d:%02d ",t1/3600,(t1/60%60),t1%60,t2/3600,(t2/60%60),t2%60);
    logs[id].push_back(string(buf)+msg);
}
bool handle(Agent &agent){
    //mutate Agent
    //if has NO more event, return false
    int id = agent.id;
    if(agent.next_room ==-1){
        LOG(agent.id,agent.t,agent.t+30,"Entry");
        agent.floor = 1, agent.t+=30, agent.next_room = 0;
        agent.pt = -1;
        if(rooms[id][0].first/100==1) agent.ele = 1;
        else agent.ele = 0;
        return true;
    }
    int rid = rooms[id][agent.next_room].first;
    int st = rooms[id][agent.next_room].second;
    if(rid/100 == agent.floor){
        //0, transfer from elevator to next room
        if(agent.ele==0){
            if(rid==100){
                LOG(id,agent.t,agent.t+30,"Exit");
                return false;
            }
            
            agent.ele = 1;
            agent.pt = -1;//no waiting
            sprintf(buf,"Transfer from elevator to room %04d",rid);
            LOG(id,agent.t,agent.t+10,string(buf));
            agent.t+=10;
        }else if(agent.ele==1){
            if(agent.t>=room_t[rid]){
                //can enter
                sprintf(buf,"Waiting in front of room %04d",rid);
                if(agent.pt!=-1) LOG(id,agent.pt,agent.t,string(buf));
                agent.pt = -1;
                sprintf(buf,"Stay in room %04d",rid);
                LOG(id,agent.t,agent.t+st,string(buf));
                agent.t+=st;
                agent.ele = 2;
                agent.next_room ++;
                room_t[rid] = agent.t;
            }else{
                if(agent.pt==-1) agent.pt = agent.t;
                agent.t = room_t[rid];
            }
        }else{
            //walk to next room
            int prid = rooms[id][agent.next_room-1].first;
            if(rid==100){
                LOG(id,agent.t,agent.t+30,"Exit");
                return false;
            }
            
            sprintf(buf,"Transfer from room %04d to room %04d",prid,rid);
            LOG(id,agent.t,agent.t+10,string(buf));
            agent.t+=10;
            agent.ele = 1;
        }
        return true;
    }else{
        if(agent.ele==2){
            int prid = rooms[id][agent.next_room-1].first;
            sprintf(buf,"Transfer from room %04d to elevator",prid);
            LOG(id,agent.t,agent.t+10,string(buf));
            agent.t+=10;
            agent.ele = 0;
        }else{
            int floor = agent.floor;
            if(elevator[floor]<agent.t) elevator[floor] = agent.t;
            int p = elevator[floor];
            if(p%5) p = p/5*5+5;
            elevator[floor] = p;
            if(p==agent.t){
                if(agent.pt!=-1)
                    LOG(id,agent.pt,agent.t,"Waiting in elevator queue");
                //enter elevator
                int d = abs(rid/100-floor)*30;
                LOG(id,agent.t,agent.t+d,"Stay in elevator");
                agent.t+=d;
                agent.floor = rid/100;
                elevator[floor]+=5;
            }else{
                if(agent.pt==-1) agent.pt = agent.t;
                agent.t = elevator[floor];
            }
        }
        return true;
    }
}
int main()
{
    char c;
    int h,m,s;
    int num,st;
    while(scanf(" %c",&c),c!='.'){
        scanf("%d:%d:%d",&h,&m,&s);
        int id = c-'A';
        start[id] = h*3600+m*60+s;
        while(scanf("%d",&num),num){
            scanf("%d",&st);
            rooms[id].push_back(make_pair(num,st));
        }
        rooms[id].push_back(make_pair(100,0));
    }
    priority_queue<Agent> pq;
    for(int i=0;i<26;i++)
        if(rooms[i].size()){
            Agent agent;
            agent.id = i;
            agent.next_room = -1;
            agent.pt = -1;
            agent.t = start[i];
            pq.push(agent);
        }
    while(!pq.empty()){
        Agent hd = pq.top();
        pq.pop();
        if(handle(hd)) pq.push(hd);
    }
    for(int i=0;i<26;i++)
        if(rooms[i].size()){
            printf("%c\n",(i+'A'));
            for(int j=0;j<logs[i].size();j++)
                printf("%s\n",logs[i][j].c_str());
            printf("\n");
        }
    return 0;
}
