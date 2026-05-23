class Solution:
    def addBinary(self, a: str, b: str) -> str:
        rev_a=a[::-1]
        rev_b=b[::-1]
        if len(a) >= len(b):
            big_num,small_num=rev_a,rev_b
        else:
            big_num,small_num=rev_b,rev_a
        
        result=""
        carry=0
        for i in range(len(small_num)):
            digit1=ord(small_num[i])-ord('0')
            digit2=ord(big_num[i])-ord('0')
            carry,cur_result = divmod((digit1 + digit2 + carry), 2)
            #print(digit1,digit2,cur_result,carry)
            result+=str(cur_result)
        
        for j in range(len(small_num),len(big_num)):
            digit = ord(big_num[j]) - ord('0')
            carry,cur_result = divmod((digit+carry),2)
            result+=str(cur_result)

        if carry==1:
            result+=str(1)

        return result[::-1]          
