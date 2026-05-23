class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        signature_to_index={}
        result=[]
        for word in strs:
            freq=[0 for _ in range(26)]
            for ch in word:
                index=ord(ch)-ord('a')
                freq[index]+=1
            
            signature=tuple(freq)

            if signature in signature_to_index:
                index=signature_to_index[signature]
                result[index].append(word)

            else:
                index=len(result)
                signature_to_index[signature]=index
                result.append([word])
        
        return result