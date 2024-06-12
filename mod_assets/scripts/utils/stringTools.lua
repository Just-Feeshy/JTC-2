local string_utils = {}

function string_utils.starts_with(str, start)
   -- if #str < #start then return false end
   return str:sub(1, #start) == start
end

function string_utils.ends_with(str, ending)
   return ending == "" or str:sub(-#ending) == ending
end

return string_utils
