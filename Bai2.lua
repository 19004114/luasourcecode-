function file_exists(file)
    local f = io.open(file, "rb")
    if f then 
        f:close() 
    end
    return f ~= nil
end
function lines_from(file)
    if not file_exists(file) then return {} end
    local lines = {}
    for line in io.lines(file) do 
      lines[#lines + 1] = line
    end
    return lines
end

local file = 'input3.txt'
local lines = lines_from(file)
local dshs = {}

for i = 1, #lines,2 do
    table.insert(dshs, {diem = lines[i], name = lines[i+1]} )
end

print("Danh sach hoc sinh: ")
for i = 1, #dshs do
    print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
end

local tt = ""
local td = 0
for i = 1, #dshs do
    if i ~= #dshs then
        for j = i + 1, #dshs do
            if dshs[i].name > dshs[j].name then
                tt = dshs[i].name
                dshs[i].name = dshs[j].name
                dshs[j].name = tt
                
                td = dshs[i].diem
                dshs[i].diem = dshs[j].diem
                dshs[j].diem = td
            end
        end
    end
end

print("Danh sach hoc sinh sau khi sap xep: ")
for i = 1, #dshs do
    print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
end

local file2 = 'input2.txt'
local lines2 = lines_from(file2)
for i = 1, #lines2,2 do
    table.insert(dshs, {diem = lines2[i], name = lines2[i+1]} )
end

print("Danh sach hoc sinh sau khi them: ")
for i = 1, #dshs do
    print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
end

for i = 1, #dshs do
    if i ~= #dshs then
        for j = i + 1, #dshs do
            if dshs[i].name > dshs[j].name then
                tt = dshs[i].name
                dshs[i].name = dshs[j].name
                dshs[j].name = tt
                
                td = dshs[i].diem
                dshs[i].diem = dshs[j].diem
                dshs[j].diem = td
            end
        end
    end
end

print("Danh sach hoc sinh moi sau khi sap xep: ")
for i = 1, #dshs do
    print("Ho ten: " .. dshs[i].name .. "\tDiem: " .. dshs[i].diem)
end