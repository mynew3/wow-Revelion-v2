/*
 * Copyright (C) 2013-2015 InfinityCore <http://www.noffearrdeathproject.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOGWORKER_H
#define LOGWORKER_H

#include "LogOperation.h"

#include <ace/Task.h>
#include <ace/Activation_Queue.h>

class LogWorker: protected ACE_Task_Base
{
    public:
        LogWorker();
        ~LogWorker();

        typedef ACE_Message_Queue_Ex<LogOperation, ACE_MT_SYNCH> LogMessageQueueType;

        enum
        {
            HIGH_WATERMARK = 8 * 1024 * 1024,
            LOW_WATERMARK  = 8 * 1024 * 1024
        };

        int enqueue(LogOperation *op);

    private:
        virtual int svc();
        LogMessageQueueType m_queue;
};

#endif
