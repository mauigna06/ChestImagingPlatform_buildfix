import os
import xml.etree.ElementTree as et

# Read the template files (TODO: move to Cmake?)
with open(os.path.join(os.path.dirname(__file__), "cipChestConventionsXmlAutoGenerated.h.template"), "rb") as f:
    template_cxx = f.read()

with open(os.path.join(os.path.dirname(__file__), "..", "cip_python", "common", "chest_conventions_static.py.template"), "rb") as f:
    template_python = f.read()

# Read the XML
with open(os.path.join(os.path.dirname(__file__), "..", "Resources", "ChestConventions.xml"), "rb") as f:
    xml_root = et.fromstring(f.read())

replacements = (
    ("ChestTypes/ChestType", "//##CHEST_TYPE_ENUM##"),
    ("ChestRegions/ChestRegion", "//##CHEST_REGION_ENUM##"),
    ("ImageFeatures/ImageFeature", "//##IMAGE_FEATURE_ENUM##"),
    ("ReturnCodes/ReturnCode", "//##RETURN_CODE_ENUM##")
)
for replacement in replacements:
    replacement_text_cxx = ""
    replacement_text_python = ""
    nodes_query = replacement[0]
    replacement_tag = replacement[1]
    for node in xml_root.findall(nodes_query):
        replacement_text_cxx += "    {},\n".format(node.find("Code").text)
        replacement_text_python += "    {} = {}\n".format(node.find("Code").text, node.find("Id").text)

    template_cxx = template_cxx.replace(replacement_tag, replacement_text_cxx)
    template_python = template_python.replace(replacement_tag, replacement_text_python)

# Replace collections (unsigned char codes)
replacement_text_cxx = ""
replacements = (
    "ChestTypes/ChestType",
    "ChestRegions/ChestRegion",
    "ImageFeatures/ImageFeature",
)
for replacement in replacements:
    for node in xml_root.findall(replacement):
        replacement_text_cxx += "            {}.push_back( (unsigned char)( {} ) );\n".format(replacement.split("/")[0],
                                                                                              node.find("Code").text)
    replacement_text_cxx += "\n"

# Replace collections (string names)
replacement_text_cxx += "\n"
replacements = (
    "ChestTypes/ChestType",
    "ChestRegions/ChestRegion",
    "ImageFeatures/ImageFeature",
)
for replacement in replacements:
    for node in xml_root.findall(replacement):
        replacement_text_cxx += "            {}Names.push_back( \"{}\" );\n".format(replacement.split("/")[1],
                                                                                    node.find("Name").text)
    replacement_text_cxx += "\n"

# PhenotypeNames
replacement_text_cxx += "\n"
replacements = (
    "BodyCompositionPhenotypeNames",
    "ParenchymaPhenotypeNames",
    "PulmonaryVasculaturePhenotypeNames",
)
for replacement in replacements:
    for node in xml_root.findall("{}/Name".format(replacement)):
        replacement_text_cxx += "            {}.push_back( \"{}\" );\n".format(replacement, node.text)
    replacement_text_cxx += "\n"

# Hierarchy map
replacement_text_cxx += "\n"
replacement_text_cxx += \
"""            // For the hierarchical relationships, leftness and rightness
            // are respected before any relationship that transcends
            // leftness or rightness. For example left lower third maps to
            // left lung, not lower third, etc. The exception to this rule
            // is that both left and right lungs are subordinate to
            // WHOLELUNG, not LEFT and RIGHT\n"""
for hierarchy_node in xml_root.findall("ChestRegionHierarchyMap/Hierarchy"):
    replacement_text_cxx += \
"""            ChestRegionHierarchyMap.insert(Region_Pair((unsigned char)({}),
                                                       (unsigned char)({}) ) );""".format(
            hierarchy_node.find("Child").text, hierarchy_node.find("Parent").text)
    replacement_text_cxx += "\n"

# Colors
i = 0
replacement_text_cxx += "\n"
replacements = (
    "ChestTypes/ChestType",
    "ChestRegions/ChestRegion")

for replacement in replacements:
    for node in xml_root.findall(replacement):
        color = node.find("Color").text.split(";")
        # replacement_text += "            double* t092 = new double[3]; t092[0] = 0.03; t092[1] = 0.03; t092[2] = 0.04; ChestTypeColors.push_back( t092 );" \
        replacement_text_cxx += "            double c{0}[] = {{{1},{2},{3}}};  {4}Colors.push_back(c{0});\n" \
            .format(i, color[0], color[1], color[2], replacement.split("/")[1])
        i += 1

    replacement_text_cxx += "\n"

template_cxx = template_cxx.replace("//##STRUCTURES##", replacement_text_cxx)

# Write output result files (TODO: move to Cmake?)
output_path_cxx = os.path.join(os.path.dirname(__file__), "cipChestConventionsXmlAutoGenerated.h")
with open(output_path_cxx, "wb") as f:
    f.write(template_cxx)
output_path_python = os.path.join(os.path.dirname(__file__), "..", "cip_python", "common", "chest_conventions_static.py")
with open(output_path_python, "wb") as f:
    f.write(template_python)

print "Convention Files generated succesfully in: ", output_path_cxx, output_path_python

