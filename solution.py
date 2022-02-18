def solution(h, q):
    parent_values = []
    root_node_value = (2**h)-1
    
    for q_value in q:
        if q_value >= root_node_value or q_value <= 0:
            parent_values.append(-1)
            continue
        
        cur_node_value = root_node_value
        cur_height = h
        
        while cur_height > 1:
            left_child = cur_node_value - (2**(cur_height-1))
            right_child = cur_node_value-1
            
            if q_value in (left_child, right_child):
                parent_values.append(cur_node_value)
                break
            
            if q_value < left_child:
                cur_node_value = left_child
            else:
                cur_node_value = right_child
            
            cur_height -= 1
            
    return parent_values
    
def main():
    l = range(1000000) 
    parents = solution(30, l)
    
if __name__ == "__main__":
    main()