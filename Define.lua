tbA = {
    {name = "Dang Long Thach - Ha", soluong = 1, hsd = "", ti_le = 10},
    {name = "Dang Long Thach - Thuong", soluong = 1, hsd = "", ti_le = 0.3},
    {name = "Do Pho Dang Long - Khoi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Hai", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Yeu Dai", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Ho Uyen", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Hang Lien", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Boi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Thuong Gioi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Ha Gioi", soluong = 1, hsd = "", ti_le = 0.01},
    {name = "Do Pho Dang Long - Y", soluong = 1, hsd = "", ti_le = 0.008},
    {name = "Do Pho Dang Long - Khi Gioi", soluong = 1, hsd = "", ti_le = 0.003},
    {name = "Dang Long Trung Luyen Ngoc", soluong = 1, hsd = "", ti_le = 0.3},
    {name = "Hon Nguyen Chan Don", soluong = 1, hsd = "", ti_le = 0.2},
    {name = "Ho Mach Don", soluong = 25, hsd = "", ti_le = 70.29},
}

function tbA:showItem()
    for i = 1, getn(self) do
        print("Ten Vat Pham: " .. self[i].name .. "\tSo luong: " .. self[i].soluong .. "\tHan Su Dung: " .. self[i].hsd .. "\tTi le: " .. self[i].ti_le)
    end
end

function tbA:getId()
    return random(1,20)
end

function tbA:getName(id)
    for i = 1, getn(self) do
        if id == i then
            return self[i].name
        end
    end
end

function tbA:getTL(id)
    for i = 1, getn(self) do
        if id == i then
            return tonumber(self[i].ti_le)
        end
    end
end

function tbA:showResult(name,ti_le)
    if name == nil then
        print("Chuc ban may man lan sau")
    elseif name ~= nil then
        if tonumber(ti_le) <= 0.01 then
            print("Chuc mung dai hiep may man trung duoc vat pham " .. name)
        elseif tonumber(ti_le) > 0.01 then
            print("Nhan duoc vat pham " .. name)
        end
    end
end