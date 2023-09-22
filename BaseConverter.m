% This will prompt you to put in a number - digits
digits = input("A number in base n: ")
%This will prompt you to put in the base that "digits" is in - base n
n = input("An integer n , where 2<=n<=10: ")
%This will propmpt you to put in the base that you want to convert to - m
m = input("An integer m, where 2<=m<=10: ")
Check(digits,n,m)
Convert_to_array(digits,n,m)


%The below function checks the validity of the input. It makes sure that
%the input can exist in the base given, and also checks that the bases
%given are between 1 and 10.
function validity = Check(digits,n,m)
    validity = true;
    while digits > 0
        digit = mod(digits,10);
        %If any integer in digit is greater than or equal to the base it is
        %in, it is invalid
        if (digit >= n)
            error("Error invalid input - digit does not exist in base given")
            validity = false;
        end
        digits = floor(digits/10);
    end
    %n and m should only be between 1 and 10
    if (n < 1 | n > 10)
        error("Error invalid base n - please use a base 1 through 10")
    elseif (m < 1 | m > 10)
        error("Error invalid base m - please use a base 1 through 10")
    end 
end



%The below function takes an input - digits, in base n, and converts it to
%base m. First it converts the input to base 10, and then converts it to
%base m.
function integer_base_m = Convert_to_array(digits,n,m)
    base_10_array = [];
    %This will separate each integer in digits so that we can convert to
    %base 10
    while digits > 0
        nums = mod(digits,10);
        base_10_array = [base_10_array,nums];
        digits = floor(digits/10);
    end
    summation = 0;
    %convert to base 10
    for i = 1:length(base_10_array)
        summation = summation + base_10_array(i)*n^(i-1);
    end
    array_base_m = [];
    %add converted numbers to array
    while summation > 0
       array_base_m = [array_base_m,mod(summation,m)];
       summation = floor(summation/m);
    end
    integer_base_m = 0;
    %convert to base m
    for i = 1:length(array_base_m)
        integer_base_m = integer_base_m + 10^(i-1)*array_base_m(i);
    end
    fprintf("Your number in base m is: %i \n", integer_base_m)
end


