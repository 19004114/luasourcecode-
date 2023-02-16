local tbl = {}
local n = 0

io.write("Nhap vao n phan tu: ")
n = io.read()

for i = 1, n do
    io.write("Nhap so thuc thu " .. i .. ": ")
    tbl[i] = io.read()
end

for i = 1, #tbl do
    print(tbl[i])
end

local min = tbl[1]
local max = tbl[1]
local t = 0
local tbc = 0

for i = 1, #tbl do
    if min > tbl[i] then
        min = tbl[i]
    end
    if max < tbl[i] then
        max = tbl[i]
    end
    t = t + tbl[i]
end

tbc = t/n

print("Phan tu nho nhat: " .. min)
print("Phan tu lon nhat: " .. max)
print("Trung binh cong cac phan tu: " .. tbc)

io.write("Cac phan tu nho hon trung binh cong: ")
for i = 1, #tbl do
    if tonumber(tbl[i]) < tbc then
        io.write(tbl[i] .. "\t")
    end
end

io.write("\nCac phan tu lon hon trung binh cong: ")
for i = 1, #tbl do
    if tonumber(tbl[i]) > tbc then
        io.write(tbl[i] .. "\t")
    end
end