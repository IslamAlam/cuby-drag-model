function id=IntegerDivisors(n)
%IntegerDivisors    Integer divisors of n
%
%id=IntegerDivisors(n)
%
%n      Positve integer, scalar
%
%id     Vector of integer divisors of n, 1<id<n
%
if numel(n)~=1, error('n must be a scalar'), end
id=[];
for k=2:n-1
    r=rem(n,k);
    if r==0, id=[id,k]; end
end
end

