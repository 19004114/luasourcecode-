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

function table.shallow_copy(t)
    local t2 = {}
    for k,v in pairs(t) do
      t2[k] = v
    end
    return t2
end

tbB = table.shallow_copy(tbA)
table.insert(tbB, {name = "Long Thach - Ha", soluong = 1, hsd = "", ti_le = 1} )
table.insert(tbB, {name = "Nhan 20 van Bac", soluong = 200000, hsd = "", ti_le = 0.3} )

Mod = {
    item = function(tbl)
        for i = 1, #tbl do
            print("Ten Vat Pham: " .. tbl[i].name .. "\tSo luong: " .. tbl[i].soluong .. "\tHan Su Dung: " .. tbl[i].hsd .. "\tTi le: " .. tbl[i].ti_le)
        end
    end,

    rand = function()
        return math.random(1,20)
    end,

    CheckVP = function(id,tbl)
        for i = 1, #tbl do
            if id == i then
                return tbl[i].name
            end
        end
    end,

    CheckTL = function(id,tbl)
        for i = 1, #tbl do
            if id == i then
                return tbl[i].ti_le
            end
        end
    end,
}

return Mod