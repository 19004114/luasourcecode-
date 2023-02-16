io.write("Nhap vao so luong hoc sinh: ")
local n = io.read()
local dshs = {}

for i = 1, n do
    table.insert(dshs, 1, {name = "", diem = 0})
end

for i = 1, #dshs do
    dshs[i].name = io.read()
    dshs[i].diem = io.read()
end

print("Danh sach hoc sinh: ")
for i = 1, #dshs do
    print(dshs[i].name .. "\n" .. dshs[i].diem)
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
    print(dshs[i].name .. "\n" .. dshs[i].diem)
end

io.write("Nhap vao so luong hoc sinh can them: ")
local new = io.read()
local dshsm = {}

for i = 1, new do
    table.insert(dshs, 1, {name = "", diem = 0})
end

for i = 1, new do
    dshs[i].name = io.read()
    dshs[i].diem = io.read()
end

print("Danh sach hoc sinh moi sau khi sap xep: ")
for i = 1, #dshs do
    print(dshs[i].name .. "\n" .. dshs[i].diem)
end