def count_substring(string, sub_string):
    sum=0
    for i in range(0,(len(string)-len(sub_string))+1):
        if(string[i:i+len(sub_string)]== sub_string):
            sum+=1
    return sum