#include <iostream>
#define limit 100
// limit will be the numbers of pair that you want to display on your screen

struct TwoNumPair{ // Two Numbers pair
    int firstNumber;
    int secondNumber;
};

int give_index(int *param_arr,int end,int param_number,int start=0){
    // Gives you the appropriate index for insertion in sorted list such that after insertion array still be sorted

    if(end < start){return start;}
    if(end == start){ // I will explain this later
        if(param_arr[start] > param_number){return start;}
        return start+1;
    }

    int mid_point = (start + end) / 2;
    
    if(param_arr[mid_point] < param_number){
        return give_index(param_arr,end=end,param_number=param_number,start=mid_point+1);
    }
    else{
        return give_index(param_arr,end=mid_point-1,param_number=param_number,start=start);
    }

}
template<class T>
void insert_into_arr(T* param_arr,int index_,T* data,int length){
    // Nothing just insertion in array

    // Now pushing every element +1 from their indexs but from last
    while (length > index_){
        param_arr[length] = param_arr[length-1];
        length--;
    }

    param_arr[index_] = *data;    
}

void RjHdNumGen(){ // Ramanujam Hardy Number generator
    int max_num = 100;
    int no_of_combination = max_num*(max_num+1)/2;
    // I have calculated this formula from hand i just found number of combination from these numbers will be sum of positive integers till max_num

    int *sumOfCubes = new int[no_of_combination];
    TwoNumPair *AllPairs = new TwoNumPair[no_of_combination];
    int size_ = 0; // Size(no_of_pairs) of both array will be equal
    
    for (int i = 1; i <= max_num; i++){
        for (int j = i; j <= max_num; j++){
            // These two loops are nothing just giving me two number pairs
            TwoNumPair * curr_pair = new TwoNumPair;
            curr_pair->firstNumber = i;
            curr_pair->secondNumber = j;

            int CurrSumOfCubes = i*i*i + j*j*j;
            // Here computing index because i want SumOfCubes array should be sorted
            // Giving argument size_-1 because i have desinged this function such that it require length-1 as end

            int index_to_insert = give_index(sumOfCubes,size_-1,CurrSumOfCubes);

            insert_into_arr<int>(sumOfCubes,index_to_insert,&CurrSumOfCubes,size_);
            insert_into_arr<TwoNumPair>(AllPairs,index_to_insert,curr_pair,size_);
            size_++;
        }
    }
    int no_of_printed = 0;

    for (int i = 0; i < size_-1; i++){
        if(sumOfCubes[i] == sumOfCubes[i+1]){
            std::cout<<"Pair1: "<<AllPairs[i].firstNumber<<" "<<AllPairs[i].secondNumber<<std::endl;
            std::cout<<"Pair2: "<<AllPairs[i+1].firstNumber<<" "<<AllPairs[i+1].secondNumber<<std::endl;
            std::cout<<"SumOfCube: "<<sumOfCubes[i]<<std::endl;
            std::cout<<"\n";
            no_of_printed++;
        }
        if (no_of_printed == limit){
            break;
        }
    }
    
    
}
int main(){
    RjHdNumGen();
    return 0;
}
