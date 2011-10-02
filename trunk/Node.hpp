/*
 * Copyright (C) 2011 BARBOTIN Nicolas
 *
 * This file is part of QtYaml.
 *
 * QtYaml is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * QtYaml is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with QtYaml.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <QtCore>
#include "qtyaml_global.hpp"

namespace YAML {

enum NodeType {
    NT_Array,
    NT_Property
};

class QTYAMLSHARED_EXPORT Node
{
public:
    Node(QString value, NodeType ntype = NT_Property, Node *nparent = 0);
    Node(QStringList nvalues, NodeType ntype = NT_Property, Node *nparent = 0);

    NodeType getNodeType();
    Node *getParent();
    QString getValue();
    QStringList getValues();

    void setParent(Node *nparent);
    void setValue(QString value);
    void setValues(QStringList nvalues);
    void setType(NodeType ntype);

    void appendValue(QString value);
    void clearValueList();

private:
    NodeType type;
    Node *parent;
    QStringList values;
};

}

#endif // NODE_HPP
