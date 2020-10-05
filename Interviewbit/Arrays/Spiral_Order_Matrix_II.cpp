vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > result;
    vector<int> init_vect((int) A, 0);
    
    for(int i = 0; i < A; ++i)
    {
        result.push_back(init_vect);
    }
    
    long int number = 1;
    long int row = 0;
    long int col = 0;
    
    bool is_row = true;
    int row_offset = 1;
    int col_offset = 1;
    
    while(number <= (A * A))
    {
        result[row][col] = number;
        ++number;
        
        if(is_row)
        {
            col += col_offset;
            
            if(col > -1 && col < A && result[row][col] == 0)
            {
                continue;
            }
            else
            {
                col -= col_offset;
                is_row = false;
                col_offset *= -1;
                row += row_offset;
            }
        }
        else
        {
            row += row_offset;
            
            if(row > -1 && row < A && result[row][col] == 0)
            {
                continue;
            }
            else
            {
                row -= row_offset;
                is_row = true;
                row_offset *= -1;
                col += col_offset;
            }
        }
    }
    
    return result;
}
