local function Show(name, ti_le)
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

local mod = require("Define")

mod.item(tbA)

local id = mod.rand()
Show(mod.CheckVP(id,tbA), mod.CheckTL(id,tbA))
Show(mod.CheckVP(id,tbB), mod.CheckTL(id,tbB))