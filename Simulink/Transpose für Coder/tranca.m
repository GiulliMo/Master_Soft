function out = tranca(in)

newTrans = {zeros(1,length(in))}

for c = 1:1:(length(in))
    newTrans(c) = in(c)
end

out = newTrans
end

