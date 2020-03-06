import logging

class Logger:
    def __init__(self,logger_name,file_log=True,level=logging.INFO,logging_path=None):
        self._log=logging.getLogger(logger_name)
        self._log.setLevel(level)
        if file_log:
            if logging_path is None:
                raise ValueError("log file path can not be empty")
            handler=logging.FileHandler(logging_path)
        else:
            handler=logging.StreamHandler()
        fmt=logging.Formatter("%(asctime)s %(name)s %(levelname)s %(message)s")
        handler.setLevel(level)
        handler.setFormatter(fmt)
        self._log.addHandler(handler)

    def debug(self,msg):
        if not isinstance(msg,str):
            raise TypeError("message must be string")
        self._log.debug(msg)

    def info(self,msg):
        if not isinstance(msg,str):
            raise TypeError("message must be string")
        self._log.info(msg)

    def warning(self,msg):
        if not isinstance(msg,str):
            raise TypeError("message must be string")
        self._log.warning(msg)

    def error(self,msg):
        if not isinstance(msg,str):
            raise TypeError("message must be string")
        self._log.error(msg)
    
    def critical(self,msg):
        if not isinstance(msg,str):
            raise TypeError("message must be string")
        self._log.critical(msg)