 #include<stdlib.h>
int cmp(const void* a, const void* b){
int* t1 = *(int**)a;
int* t2 = *(int**)b;
int diff1 = t1[1]-t1[0];
int diff2 = t2[1]-t2[0];
return diff2-diff1;
} 

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks,tasksSize,sizeof(int*),cmp);
    int energy = 0;
    int answer = 0;
    for(int i=0;i<tasksSize;i++){
        int actual = tasks[i][0];
        int minimum = tasks[i][1];
        if(energy<minimum){
            int need = minimum - energy;
            answer += need;
            energy += need;
        }
        energy -= actual;
    }
    return answer;
}