cmessage=input('请输入你的加密信息：');
clist=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'];
r=size(cmessage);
c=r(2);r=r(1);
imessage=zeros(r,c);
for i=1:c
    for j=1:26
        if cmessage(i)==clist(j)
            imessage(i)=j;
            break;
        end
    end
end
n=c;
key=randi([1,26],n,n);
key_inv=inv(key);
disp("random key:");
disp(key);
cipher=imessage*key;
disp('cipher:');
disp(cipher);
decode=cipher*key_inv;
cdecode=[''];

for i=1:c
    for j=1:26
        if int8(decode(i))==j
            cdecode(i)=clist(j);
            break;
        end
    end
end
disp('decode:');
disp(cdecode);
