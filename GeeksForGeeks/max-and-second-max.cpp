vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    map<int,int>m1;
    for(int i=0;i<sizeOfArray;i++){
        m1[arr[i]]++;
    }
    auto it = m1.rbegin();
    vector<int>res;
    res.push_back(it->first);
    it++;
    if(it==m1.rend()){
        res.push_back(-1);
    }
    else res.push_back(it->first);
    return res;
    /*********************************
     * Your code here
     * This function should return a
     * vector with first element as
     * max and second element as 
     * second max
     * *******************************/
     
}
