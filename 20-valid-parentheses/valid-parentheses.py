class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        for ch in s:
            if ch=='(' or ch=='{' or ch=='[':
                stack.append(ch)
            else:
                if len(stack) < 1:
                    return False
                top=stack.pop()
                if (ch==')' and top!='(') or (ch=='}' and top!='{') or (ch==']' and top!='['):
                    return False
        if len(stack) > 0:
            return False
        return True