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

#include "Node.hpp"

namespace YAML {

Node::Node(QString value, NodeType ntype, Node *nparent) {
    values.append(value);
    type = ntype;
    parent = nparent;
}

Node::Node(QStringList nvalues, NodeType ntype, Node *nparent) {
    values = nvalues;
    type = ntype;
    parent = nparent;
}

NodeType Node::getNodeType() {
    return type;
}

Node *Node::getParent() {
    return parent;
}

QString Node::getValue() {
    if(type != NT_Property)
        return QString();

    return values[0];
}

QStringList Node::getValues() {
    if(type != NT_Array)
        return QStringList();

    return values;
}

void Node::setValue(QString value) {
    if(type != NT_Property)
        return;

    values[0] = value;
}

void Node::setValues(QStringList nvalues) {
    if(type != NT_Array)
        return;

    values = nvalues;
}

void Node::setParent(Node *nparent) {
    parent = nparent;
}

void Node::setType(NodeType ntype) {
    type = ntype;
}

void Node::appendValue(QString value) {
    if(type != NT_Array)
        return;

    values.append(value);
}

void Node::clearValueList() {
    if(type != NT_Array)
        return;

    values.clear();
}

}
