$ (1+x+x^2+x^3+...+x^N) % M \
<=>[1+(x+x^2+...+x^(N/2)) + x^(N/2)*(x+x^2+...+x^(N/2))] % M \
<=>1%M + [(x+x^2+...+x^(N/2)) * (x^(N/2) + 1)] % M$

Đặt $F(x,n)=(x+x^1+x^2+...+x^n)%M$. 

Khi đó, kết quả bài toán sẽ là $[1+F(x,n)]%M$.

Lưu ý khi tính $F(x,n)$ trong trường hợp $n$ lẻ (tức $n%2 = 1$):
$F(x,n)=x*(1+F(x,n-1))$
