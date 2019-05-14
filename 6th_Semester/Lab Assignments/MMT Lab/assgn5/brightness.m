function f = brightness(I)
[w,h,colormap] = size(I);
for i=1:w
    for j=1:h
        if(I(i,j,1)<=215)
            I(i,j,1) = I(i,j,1) + 35;
        end
        if(I(i,j,2)<=215)
            I(i,j,2) = I(i,j,2) + 35;
        end
         if(I(i,j,3)<=215)
            I(i,j,3) = I(i,j,3) + 35;
         end
    end
end
f = I;
end
  

