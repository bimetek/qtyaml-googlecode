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

#include "Document.hpp"

namespace YAML {

Document::Document(QString file, QIODevice::OpenModeFlag openMode) :
    yamlFile(file)
{

    if(!QFile::exists(file)) {
        qDebug() << "File not found : " << file;
    }

    yamlFile.open(openMode);
    opened = openMode;

    if(openMode == QIODevice::ReadOnly || openMode == QIODevice::ReadWrite) {
        //Reading lines...
        while(!yamlFile.atEnd())
            lines.append(QString(yamlFile.readLine()).remove("\n"));
    }
}

Document::~Document() {
    yamlFile.close();
}

Node *Document::getNode(QString name, QString defaultValue) {
    Node *node = new Node(defaultValue);

    for(int i = 0; i < lines.count(); i++) {
        if(!lines[i].isEmpty() && !lines[i].startsWith("#")) {
            QString line = lines[i].right(lines[i].size() - getLineRealStart(lines[i]));
            if(line.startsWith(name + ":")) {
                QString value = line.split(":")[1];
                value = value.right(value.size() - getLineRealStart(value));
                if(value.startsWith("{")) {
                    //Block !
                } else {
                    value = removeComments(value);
                    if(value.isEmpty() || value.startsWith("-")) {
                        //Array !
                        node->setType(NT_Array);
                        node->clearValueList();
                        if(value.startsWith("-")) {
                            QString firstArrayValue = value.right(value.size() - 1);
                            firstArrayValue = firstArrayValue.right(firstArrayValue.size() - getLineRealStart(firstArrayValue));
                            node->appendValue(firstArrayValue);
                        }
                    } else {
                        //Simple value...
                        node->setValue(value);
                        break;
                    }
                }
            } else if(node->getNodeType() == NT_Array && line.startsWith("-")) {
                //Adding value to array...
                QString value = removeComments(line.right(line.size() - 1));
                value = value.right(value.size() - getLineRealStart(value));
                node->appendValue(value);
            }
        }
    }

    return node;
}

int Document::getLineRealStart(QString line) {
    int ret = -1;

    for(int i = 0; i < line.size(); i++) {
        if(line[i] != ' ') {
            ret = i;
            break;
        }
    }

    return ret;
}

QString Document::removeComments(QString line) {
    QString ret = line;
    int dieseAt = -1;

    for(int i = line.size() - 1; i > 0; i--) {
        if(line[i] == '#') {
            dieseAt = i - 1;
            break;
        }
    }

    if(dieseAt != -1)
        ret = line.left(dieseAt);

    while(ret[ret.size() - 1] == ' ')
        ret = ret.left(ret.size() - 1);

    return ret;
}

}
