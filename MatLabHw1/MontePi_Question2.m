%Part b1

%set an empty array to store our starting times
times = [];
%set empty array to store our final values of Pi
Pi_Values = [];
%Start timing our loop
start_time = tic;
for i = 1:500
    %Store our outputs of the function in an array so we can access them 
    [a, b, c] = MontePi(i);
    %add our pi approximation to our array in order to plot
    Pi_Values = [Pi_Values, a];
    %stop recording 
    times = [times, toc];
end
%Plot, Label each axis 
plot(times,Pi_Values)
xlabel("N");
ylabel("Pi_Approximations");

%Part b2

%Store the x and y axes here
X_Axis = [];
Y_Axis = [];


for i = 1:500
    %store output of function in array so we can use the outputs that we
    %want in the plot
    [a,b,c] = MontePi(i);
    MontePi(i);
    %add b to our y axis
    Y_Axis = [Y_Axis, b];
    %add n to our x axis
    X_Axis = [X_Axis, i];
end
%plot x and y
figure2 = (plot(X_Axis, Y_Axis));



%Part b3
counter = 0;
for i = 1:200
    %x and y are random points between 0 and 1, generated by rand function
    x = rand;
    y = rand;
    %To make the points inside the circle blue, and the points outside red
    if ( x^2 + y^2 <= 1)
        %make points inside circle blue
        plot(x, y,"Color", "b", "Marker","o")
        %used to capture every value of (x,y)
        hold on;
        counter = counter + 1;
    else
        %make points outside circle red
        plot(x,y, 'color','r','Marker','o');

    end 
end
hold off;

%Function to approximate Pi - Part a

function [pi_approx,absolute_error,relative_error] = MontePi(n)
    %counter variable will count the number of points in unit circle
    counter = 0;
    %Create random points between 0 and 1, if they are inside the unit
    %circle we will count them 
    for i = 1:n
        x = rand;
        y = rand;
        %If the below statement is true, then the point is in the unit
        %circle and we want to count it
        if (x^2 + y^2 <= 1)
            counter = counter +1;
        end
    end
    %Our approximation will be the ratio of points inside the circle times
    %4
    pi_approx = (counter / n)*4;
    absolute_error = abs(pi-pi_approx);
    relative_error = (abs(pi-pi_approx)/pi);
    fprintf("The approximated value for Pi is: %f \n The absolute error: %f \n " + ...
        "The Relative error %f \n", pi_approx, absolute_error, relative_error);
end