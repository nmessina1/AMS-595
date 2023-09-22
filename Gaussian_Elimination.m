%a is our nxn matrix
a = [10 -20 10 ; 2 1 -3; 4 -7 1];
%c here is our "b" - the end result
c = [0; 5; -1];

n = height(a_augmented)


for col = 1:n-1
    for row = col + 1:n
        
        %current cell
        cur_cell = a_augmented(row,col);
        %current pivot
        cur_pivot = a_augmented(col,col);
        %multiple that we will use to set current cell to 0
        fraction = cur_cell/cur_pivot;
        %setting current row to 0, must multiple whole row by same factor
        modified_top_row = fraction * a_augmented(col,:);
        a_augmented(row,:) = a_augmented(row,:) - modified_top_row
        
    end
end

%Back Substitution
x = zeros(n,1) %initialize vector answer x
x(n) = a_augmented(n,n+1)/a_augmented(n,n)
for row_2=n-1:-1:1 %must start backwards from n-1 
    running_total = 0
    for column=row_2+1:n
        new_x = a_augmented(row_2,column)*x(column,:) %solve for variables
        running_total = running_total + new_x 
        divisor = a_augmented(row_2,row_2)
        x(row_2,:) = (a_augmented(row_2,n+1) - running_total)/divisor
    end
end
