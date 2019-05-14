function mean(b)
       [m,n,colormap]=size(b);
        x=b(:,:,1);
        y=b(:,:,2);
        z=b(:,:,3);
        % for 3 * 3
        for i=1:m-2
            sum1 = 0;
            sum2 = 0;
            sum3=0;
            for j=1:n-2
                for r=i:(i+2)
                    for s=j:(j+2)
                        sum1 = int16(sum1) + int16(x(r,s));
                        sum2 = int16(sum2) + int16(y(r,s));
                        sum3 = int16(sum3) + int16(z(r,s));
                    end
                end
                    avg1 = int16(sum1 / 9);
                    avg2 = int16(sum2 / 9);
                    avg3 = int16(sum3 / 9);

                    x(i+1,j+1) = avg1;
                    y(i+1,j+1) = avg2;
                    z(i+1,j+1) = avg3;
                    sum1=0;sum2=0; sum3 = 0;
            end
        end
        c(:,:,1)=x;
        c(:,:,2)=y;
        c(:,:,3)=z;
        figure,imshow(rgb2gray(c)),title('Mean filer from self written function');
    end
