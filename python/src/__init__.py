"""
    otsmolyak --- An OpenTURNS module
    ==================================

    Contents
    --------
      'otsmolyak' is a module for OpenTURNS

"""

import sys
if sys.platform.startswith('win'):
    # this ensures OT dll is loaded
    import openturns

from .otsmolyak import *

__version__ = '0.0'

