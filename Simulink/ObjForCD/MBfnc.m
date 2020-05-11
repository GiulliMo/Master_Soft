function y  = MBfnc
persistent counter strArray
y=1;
if isempty(counter)
    counter = 1;
    
end

if isempty(strArray)
    strArray = [struct('a',multiObjectTracker,'b',multiObjectTracker)];
end

obj = multiObjectTracker();
cellOfObj = {obj; obj};

if isempty(cellOfObj)
    element = struct('a',multiObjectTracker,'b',multiObjectTracker);
elseif numel(cellOfObj)==1
    element = struct('a',cellOfObj{1,1},'b',multiObjectTracker);
elseif numel(cellOfObj)==2
    element = struct('a',cellOfObj{1,1},'b',multiObjectTracker);
end

strArrayOut = [strArray element]
%strArrayOut = strArray    
counter = counter + 1;   
end

