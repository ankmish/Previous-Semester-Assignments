function [code1, average_length] = binaryHuffman(p)
set(0,'RecursionLimit',1e4);  % set recursion limit .. good habit 
% p should be a probability vector (row or column)
% code1 outputs the corresponding codewords (obtained by Huffman coding)
%{
if (iscolumn(p))
    p = p.';
elseif (isrow(p))
else
    error('input not a vector');
end
%}
if ((sum(p>=0)~=length(p)))
    error('input needs to be a probability vector');
end

p = p/sum(p);
if(length(p)>2)
    [pdes,idx] = sort(p,'descend');
    q1 = pdes(1:(length(pdes)-1));
    q1(length(pdes)-1) = pdes(length(pdes)-1)+pdes(length(pdes));
    old_code = binaryHuffman(q1);
    new_code = [old_code(1:(length(old_code)-1)) strcat(old_code{length(old_code)},'0') strcat(old_code{length(old_code)},'1')];
    code1(idx) = new_code;
    
elseif(length(p)==2)
    code1 = {'0', '1'};
else
    error('No coding needed!');
end
l1 = cellfun(@length, code1);
average_length = sum(l1.*p);
end