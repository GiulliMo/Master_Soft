a=1
b=1
r=0.1
vx=0
vy=0

J=(1/r)*[1 1 a+b;       %Vorne rechts
        1 -1 -(a+b);    %Vorne links   
        1 1 -(a+b);     %Hinten links
        1 -1 a+b]       %Hinten rechts


J3=(1/r)*[1 1 a+b;       %Vorne rechts
        1 -1 -(a+b);    %Vorne links   
        1 1 -(a+b)]     %Hinten links    