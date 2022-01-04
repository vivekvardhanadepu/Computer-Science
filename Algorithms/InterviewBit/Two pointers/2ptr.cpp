 for (int i = 0; i < A.size(); i++) 
            for (int j = A.size() - 1; j >= 0; j--) {
                if (i != j && A[i] + A[j] == 0) return true; // solution found. 
                if (A[i] + A[j] < 0) break; // Clearly A[i] + A[j] would decrease as j decreases.
            }
