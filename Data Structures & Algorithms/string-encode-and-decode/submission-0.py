class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_string = ""
        for s in strs:
            encoded_string += str(len(s)) + "#" + s
        return encoded_string

    def decode(self, str) -> List[str]:
        decoded_string, i = [], 0

        while i < len(str):
            
            j = i
            
            while str[j] != "#":
                j += 1
            
            length = int(str[i:j])

            decoded_string.append(str[j+1 : j+1+length])

            i = j + 1 + length
        
        return decoded_string
