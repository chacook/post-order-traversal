#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<assert.h>

int64_t* solution(int64_t h, int64_t* list, int len); 
int64_t two_to_n(int64_t n);

int main(){
	const int len = 1000000;
	int64_t list[len];
	int64_t height = 30;
	int64_t* parents;

	for (int i = 0; i < len; i++){
		list[i] = i + 1;
	}

	parents = solution(height, list, len);
	
	return 0;
}

int64_t* solution(int64_t h, int64_t* list, int len){
	int64_t cur_height, cur_node, left_child, right_child;
	int64_t root = two_to_n(h) - 1;
	int64_t* parents = (int64_t*)malloc(sizeof(int64_t) * len);
	
	if (!parents){
		printf("Malloc failed.\n");
		exit(1);
	}
	
	for (int i = 0; i < len; i++){
		if (list[i] >= root || list[i] <= 0){
			parents[i] = -1;
			continue;
		}
		
		cur_node = root;
		
		for (cur_height = h; cur_height >= 1; cur_height--){
			left_child = cur_node - two_to_n(cur_height-1);
			right_child = cur_node - 1;
					
			if (list[i] == left_child || list[i] == right_child){
				parents[i] = cur_node;
				break;
			}
			
			cur_node = list[i] < left_child ? left_child : right_child;
		}
	}
	
	return parents;
}

int64_t two_to_n(int64_t n){
	assert(n >= 0 && n <= 62);
	int64_t one = 1;
	return one << n; 
}
